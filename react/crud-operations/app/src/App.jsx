// App.js
import React, { useEffect, useState } from "react";
import api from "./shared/axios";
import "./App.css";

export default function App() {
  const [student, setStudent] = useState({
    regNo: "",
    name: "",
    course: "",
    cat1: "",
    cat2: "",
    da1: "",
    da2: "",
    quiz: "",
    fat: ""
  });

  const [students, setStudents] = useState([]);

  const convert = {
    cat1: (val) => (val / 50) * 15,
    cat2: (val) => (val / 50) * 15,
    da1: (val) => (val / 10) * 10,
    da2: (val) => (val / 10) * 10,
    quiz: (val) => (val / 10) * 10,
    fat: (val) => (val / 100) * 40
  };

  const getConverted = (key) => {
    const value = parseFloat(student[key]);
    return isNaN(value) ? 0 : convert[key](value).toFixed(2);
  };

  const handleChange = (e) => {
    setStudent({ ...student, [e.target.name]: e.target.value });
  };

  const handleSubmit = async (e) => {
    e.preventDefault();

    const newEntry = {
      ...student,
      converted: {
        cat1: getConverted("cat1"),
        cat2: getConverted("cat2"),
        da1: getConverted("da1"),
        da2: getConverted("da2"),
        quiz: getConverted("quiz"),
        fat: getConverted("fat"),
      }
    };

    await api.post("/students", newEntry);
    setStudent({
      regNo: "",
      name: "",
      course: "",
      cat1: "",
      cat2: "",
      da1: "",
      da2: "",
      quiz: "",
      fat: ""
    });
    fetchStudents();
  };

  const fetchStudents = async () => {
    const res = await api.get("/students");
    setStudents(res.data);
  };

  useEffect(() => {
    fetchStudents();
  }, []);

  const getInternal = (converted) => {
    const internal = parseFloat(converted.cat1) +
      parseFloat(converted.cat2) +
      parseFloat(converted.da1) +
      parseFloat(converted.da2) +
      parseFloat(converted.quiz);
    return internal.toFixed(2);
  };

  return (
    <div className="App">
      <h2>Student Marks Entry</h2>
      <form onSubmit={handleSubmit}>
        {["regNo", "name", "course", "cat1", "cat2", "da1", "da2", "quiz", "fat"].map((field) => (
          <div key={field}>
            <input
              name={field}
              placeholder={field.toUpperCase()}
              value={student[field]}
              onChange={handleChange}
              required
            />
            {["cat1", "cat2", "da1", "da2", "quiz", "fat"].includes(field) && (
              <p>Converted: {getConverted(field)}</p>
            )}
          </div>
        ))}
        <button type="submit">Submit</button>
      </form>

      <h2>SET 1: Internals + FAT</h2>
      <ul>
        {students.map((s, i) => {
          const internal = parseFloat(getInternal(s.converted));
          const finalInternal = internal < 30 ? internal + 5 : internal;
          return (
            <li key={i}>
              <b>{s.name}</b> ({s.regNo})<br />
              Internals: {internal} {internal < 30 && "(+5 bonus)"}<br />
              Final Internals: {finalInternal.toFixed(2)} <br />
              FAT: {s.fat} (converted: {s.converted.fat})
            </li>
          );
        })}
      </ul>

      <h2>SET 2: Students with CAT1 & CAT2 {'<'} 15</h2>
      <ul>
        {students
          .filter((s) => s.converted.cat1 < 15 && s.converted.cat2 < 15)
          .map((s, i) => {
            const cat1 = Math.min(15, parseFloat(s.converted.cat1) + 5).toFixed(2);
            const cat2 = Math.min(15, parseFloat(s.converted.cat2) + 5).toFixed(2);
            return (
              <li key={i}>
                <b>{s.name}</b> ({s.regNo})<br />
                Original CAT1: {s.converted.cat1}, Updated: {cat1}<br />
                Original CAT2: {s.converted.cat2}, Updated: {cat2}
              </li>
            );
          })}
      </ul>
    </div>
  );
}
