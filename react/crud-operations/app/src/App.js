import react, { useEffect, useState } from 'react';
import api from './shared/axios';
import "./App.css"

export default function App() {
  const [users, setUsers] = useState([])
  const [newUser, setNewUser] = useState({ name: '', email: '' });

  const fetchUsers = async () => {
    const res = await api.get('/users');
    setUsers(res.data);
  }

  const addUser = async () => {
    if (!newUser.name || !newUser.email) return;
    await api.post('/users', newUser);
    setNewUser({ name: '', email: '' });
    fetchUsers();
  }

  const deleteUser = async (id) => {
    await api.delete(`/users/${id}`);
    fetchUsers();
  }

  const updateUser = async (id, updatedData) => {
    await api.put(`/users/${id}`, updatedData);
    fetchUsers();
  }

  useEffect(() => {
    fetchUsers();
  }, [])

  return (
    <div class='App'>
      <h2>Add User</h2>
      <form>
        <input
          placeholder='Name'
          required
          value={newUser.name}
          onChange={e => setNewUser({ ...newUser, name: e.target.value })}
        />
        <input
          placeholder='Email'
          required
          value={newUser.email}
          onChange={e => setNewUser({ ...newUser, email: e.target.value })}
        />
        <button onClick={addUser}>Submit</button>
      </form>
      <h2>User List</h2>
      <ul>
        {
          users.map(user => (
            <div key={user.id}>
              <p>
                {user.id} {user.name} {user.email}
              </p>
              <button onClick={() => deleteUser(user.id)}>Delete</button>
              <button onClick={() => updateUser(user.id, {
                name: prompt("Enter name: ", user.name),
                email: prompt("Enter email: ", user.email)
              })}
              >Edit</button>
            </div>
          ))
        }
      </ul>
    </div>
  );

}