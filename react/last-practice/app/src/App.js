import React, { useState, useEffect } from "react";
import api from "./shared/api";

export default function App() {
  const schema = {
    regNo: "",
    name: "",
    course: "",
    cat1: "",
    cat2: "",
    da1: "",
    da2: "",
    quiz: "",
    fat: "",
    convert: {
      cat1: '',
      cat2: '',
      da1: '',
      da2: '',
      quiz: '',
      fat: ''
    }
  };

  const [users, setUsers] = useState([]);
  const [user, setUser] = useState(schema);
  const [formErrors, setFormErrors] = useState({});

  const convert = {
    cat1: (val) => (val / 50) * 15,
    cat2: (val) => (val / 50) * 15,
    da1: (val) => (val / 10) * 10,
    da2: (val) => (val / 10) * 10,
    quiz: (val) => (val / 10) * 10,
    fat: (val) => (val / 100) * 40
  };

  const patterns = {
    regNo: /^[0-9]{2}[A-Z]{3}[0-9]{4}$/,
    name: /^[A-Za-z ]{3,}$/,
    course: /^[A-Z]{3,}[0-9]*$/,
    cat1: /^([0-4]?[0-9]|50)(\.[0-9]{1,2})?$/,
    cat2: /^([0-4]?[0-9]|50)(\.[0-9]{1,2})?$/,
    da1: /^([0-9]|10)(\.[0-9]{1,2})?$/,
    da2: /^([0-9]|10)(\.[0-9]{1,2})?$/,
    quiz: /^([0-9]|10)(\.[0-9]{1,2})?$/,
    fat: /^([0-9]{1,2}|100)(\.[0-9]{1,2})?$/
  };

  const handleChange = (e) => {
    const { name, value } = e.target;

    setUser(prev => {
      const updatedUser = {
        ...prev,
        [name]: value
      };

      if (convert[name]) {
        updatedUser.convert = {
          ...prev.convert,
          [name]: convert[name](parseFloat(value) || 0).toFixed(2)
        };
      }

      return updatedUser;
    });

    setFormErrors(prev => ({ ...prev, [name]: "" })); // Clear error on change
  };

  const validateForm = () => {
    const errors = {};
    for (let field in patterns) {
      if (!patterns[field].test(user[field])) {
        errors[field] = `Invalid ${field.toUpperCase()}`;
      }
    }
    return errors;
  };

  const addUser = async (e) => {
    e.preventDefault();
    const errors = validateForm();

    if (Object.keys(errors).length > 0) {
      setFormErrors(errors);
      return;
    }

    await api.post('/users', user);
    setUser(schema);
    setFormErrors({});
    fetchUsers();
  };

  const fetchUsers = async () => {
    const res = await api.get('/users');
    setUsers(res.data);
  };

  useEffect(() => {
    fetchUsers();
  }, []);

  const renderInput = (label, name) => (
    <>
      <input
        name={name}
        placeholder={`Enter ${label}`}
        value={user[name]}
        onChange={handleChange}
        style={{ borderColor: formErrors[name] ? 'red' : undefined }}
      />
      {formErrors[name] && <small style={{ color: 'red' }}>{formErrors[name]}</small>}
    </>
  );

  return (
    <>
      <h2>Fill</h2>
      <form onSubmit={addUser}>
        {renderInput("RegNo", "regNo")}
        {renderInput("Name", "name")}
        {renderInput("Course", "course")}
        {renderInput("CAT1", "cat1")}
        {renderInput("CAT2", "cat2")}
        {renderInput("DA1", "da1")}
        {renderInput("DA2", "da2")}
        {renderInput("Quiz", "quiz")}
        {renderInput("FAT", "fat")}
        <button type="submit">Submit</button>
      </form>

      <div>
        <h3>Converted Scores:</h3>
        <p>CAT1: {user.convert.cat1}</p>
        <p>CAT2: {user.convert.cat2}</p>
        <p>DA1: {user.convert.da1}</p>
        <p>DA2: {user.convert.da2}</p>
        <p>Quiz: {user.convert.quiz}</p>
        <p>FAT: {user.convert.fat}</p>
      </div>

      <h2>List</h2>
      <div>
        {users.map(user => (
          <div key={user.id}>
            <p>
              {user.regNo} {user.name} {user.course} {user.cat1} {user.cat2} {user.da1} {user.da2} {user.quiz} {user.fat}
            </p>
          </div>
        ))}
      </div>
    </>
  );
}
