import "./App.css";
import {useState, useEffect} from 'react';
import Axios from 'axios';

const API_URL = 'http://localhost:4000';

function App() {
    const [users, setUsers] = useState([]);
    const [id, setId] = useState("");
    const [name, setName] = useState("");
    const [updated, setUpdated] = useState({
        id: "",
        name: ""
    });

    useEffect(() => {
        loadData();
    }, []);

    const loadData = async () => {
        const response = await Axios.get(`${API_URL}/users`)
        console.log(response.data);
        setUsers(response.data);
    };

    const addUser = (e) => {
        e.preventDefault();
        Axios.post(`${API_URL}/users/`, {
            id, name
        }).then(() => {
            setId("");
            setName("");
        }).catch((err) => {
            console.log(err);
        });
        setTimeout(() => {
            loadData();
        }, 500);
    };

    const deleteUser = (id) => {
        Axios.delete(`${API_URL}/users/${id}`);
        setTimeout(() => {
            loadData();
        }, 500);
    };

    const updateUser = () => {
        Axios.put(`${API_URL}/users/${updated.id}`, {
            id: updated.id,
            name: updated.name
        }).then((response) => {
            console.log(response);
        }).catch((e) => {
            console.log(e);
        });
        setTimeout(() => {
            loadData();
        }, 500);
    };

    return (
        <div className="App">
            <input 
                placeholder="Enter ID..."
                value={id}
                onChange={e => setId(e.target.value)}
            />
            <input 
                placeholder="Enter Name..."
                value={name}
                onChange={e => setName(e.target.value)}
            />
            <button onClick={addUser}>Add</button>

            {
                users.map(e => (
                    <div key={e.id}>
                        {e.id} {e.name}
                        <button onclick={() => {deleteUser(e.id)}}>Delete</button>

                        <input 
                            type="text"
                            placeholder="Enter ID"
                            onChange={e => setUpdated({...updated, id: e.target.value})}
                        />

                        <input 
                            type="text"
                            placeholder="Enter Name"
                            onChange={e => setUpdated({...updated, name: e.target.value})}
                        />
                        <button onclick={updateUser}>Update</button>
                    </div>
                ))
            }
        </div>
    )
}

export default App;