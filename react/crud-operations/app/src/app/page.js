"use client"

import React, { useEffect, useState } from 'react';
import api from '../api/axios';

function App() {
  const [users, setUsers] = useState([]);
  const [newUser, setNewUser] = useState({ name: '', email: '' });

  // Read
  const fetchUsers = async () => {
    const res = await api.get('/users');
    setUsers(res.data);
  };

  // Create
  const addUser = async () => {
    if (!newUser.name || !newUser.email) return;
    await api.post('/users', newUser);
    setNewUser({ name: '', email: '' });
    fetchUsers();
  };

  // Delete
  const deleteUser = async (id) => {
    await api.delete(`/users/${id}`);
    fetchUsers();
  };

  // Update
  const updateUser = async (id, updatedData) => {
    await api.put(`/users/${id}`, updatedData);
    fetchUsers();
  };

  useEffect(() => {
    fetchUsers();
  }, []);

  return (
    <div style={{ padding: '20px' }}>
      <h2>User List</h2>
      <input
        placeholder="Name"
        value={newUser.name}
        onChange={e => setNewUser({ ...newUser, name: e.target.value })}
      />
      <input
        placeholder="Email"
        value={newUser.email}
        onChange={e => setNewUser({ ...newUser, email: e.target.value })}
      />
      <button onClick={addUser}>Add User</button>

      <ul>
        {users.map(user => (
          <li key={user.id}>
            <b>{user.name}</b> — {user.email}
            <button onClick={() => deleteUser(user.id)}>Delete</button>
            <button
              onClick={() =>
                updateUser(user.id, {
                  name: prompt('New name', user.name),
                  email: prompt('New email', user.email)
                })
              }
            >
              Edit
            </button>
          </li>
        ))}
      </ul>
    </div>
  );
}

export default App;
