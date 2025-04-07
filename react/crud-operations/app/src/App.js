import React, { useEffect, useState } from 'react';
import api from './shared/axios';
import "./App.css";

export default function App() {
  const [users, setUsers] = useState([]);
  const [newUser, setNewUser] = useState({ name: '', email: '' });
  const [draggedUser, setDraggedUser] = useState(null);

  const fetchUsers = async () => {
    const res = await api.get('/users');
    setUsers(res.data);
  };

  const addUser = async (e) => {
    e.preventDefault();
    if (!newUser.name || !newUser.email) return;
    await api.post('/users', newUser);
    setNewUser({ name: '', email: '' });
    fetchUsers();
  };

  const deleteUser = async (id) => {
    await api.delete(`/users/${id}`);
    fetchUsers();
  };

  const updateUser = async (id, updatedData) => {
    await api.put(`/users/${id}`, updatedData);
    fetchUsers();
  };

  useEffect(() => {
    fetchUsers();
  }, []);

  const handleDragStart = (user) => {
    setDraggedUser(user);
  };

  const handleDrop = async (targetUser) => {
    if (draggedUser && draggedUser.id !== targetUser.id) {
      await updateUser(targetUser.id, {
        name: draggedUser.name,
        email: draggedUser.email
      });
      fetchUsers();
    }
  };

  const allowDrop = (e) => {
    e.preventDefault();
  };

  return (
    <div className='App'>
      <h2>Add User</h2>
      <form onSubmit={addUser}>
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
        <button type='submit'>Submit</button>
      </form>

      <h2>User List</h2>
      <ul>
        {users.map(user => (
          <div
            key={user.id}
            className='user'
            draggable
            onDragStart={() => handleDragStart(user)}
            onDrop={() => handleDrop(user)}
            onDragOver={allowDrop}
            style={{ border: '1px solid gray', padding: '8px', margin: '8px', borderRadius: '4px' }}
          >
            <p>
              <span style={{ color: 'darkgrey' }}>
                {user.id}
              </span>
              <b>
                {user.name}
              </b>
              <a href={`mailto:${user.email}`}>
                {user.email}
              </a>
            </p>

            <button onClick={() => deleteUser(user.id)}>Delete</button>
            <button onClick={() => updateUser(user.id, {
              name: prompt("Enter name:", user.name),
              email: prompt("Enter email:", user.email)
            })}>Edit</button>
          </div>
        ))}
      </ul>
    </div>
  );
}
