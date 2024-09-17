const express = require('express');
const app = express();
const path = require('path');
const PORT = 3000;
const users = [];

app.use(express.json());

app.get('/', (req, res) => {
    res.sendFile(path.join(__dirname, 'index.html'));
  });

app.get('/users', (req,res) => {
    res.json(users);
});

app.post('/users', (req,res) => {
    const user = req.body;
    users.push(user);
    res.status(201).json(user);
})

app.get('/users/:id', (req,res) => {
    const {id} = req.params;
    const user = users.find(u => u.id === parseInt(id));

    if (!user) {
        return res.status(404).json({error: 'User not found!'})
    }

    res.json(user);
})

app.put('/users/:id', (req,res) => (req,res) => {
    const {id} = req.params;
    const userIndex = users.findIndex(u => u.id === parseInt(id));

    if (userIndex === -1) {
        return res.status(404).json({ error: 'User not found' });
    }

    users[userIndex] = { ...users[userIndex], ...req.body };
    res.json(users[userIndex]);
})

app.delete('/users/:id', (req,res) => {
    const {id} = req.params;
    const userIndex = users.findIndex(u => u.id === parseInt(id));

    if (userIndex === -1) {
        return res.status(404).json({error: 'User not found'});
    }

    users.splice(userIndex, 1);
    res.status(204).end();
})

app.listen(PORT, () => {
  console.log(`Server is running on http://localhost:${PORT}`);
});
