import './App.css';
import {useEffect,useState} from "react"
import Axios from "axios"
function App() {
 //for getting the input from the text field
 const [users,setUsers] = useState([]);
 const [id,setId] = useState("");
 const[name,setName] = useState("");
 const[updated,setUpdated] = useState({id:"", name:""});
// const [users,setUsers] = useState([]); //dummy empty array to get the value and check
 useEffect(() => {
 loadData();
 },[]);
//get user from API
const loadData = async () => {
 const response = await Axios.get('http://localhost:4000/users');
 console.log(response.data);
 setUsers(response.data) //to pass the fetched data
}
//Add user
const AddUser = (e) => {
 e.preventDefault();
 Axios.post('http://localhost:4000/users', {
 id,name
 }).then(() => {
 setId(""); setName("");
 }).catch((err)=> {
 console.log(err);
 })
 setTimeout(()=>
 {
 loadData();
 },500)
}
//delete user
const deleteUser = (id) => {
 Axios.delete(`http://localhost:4000/users/${id}`);
 setTimeout(() => {
 loadData()
 },500)
}
//update user
const updateUser = () => {
 Axios.put(`http://localhost:4000/users/${updated.id}`,{
 id:updated.id, name:updated.name
 }).then((response) => {
 console.log(response);
}).catch((e) => {console.log(e)})
setTimeout(() => {
 loadData()
}, 500);
}
return (
 <div className="App">
 <input placeholder='Enter ID ..' value={id} onChange={e => setId(e.target.value)}/>
 <input placeholder='Enter Name ..' value={name} onChange={e => setName(e.target.value)} />
 <button onClick = {AddUser}>Add</button>

 {
 users.map(e => (
 <div key={e.id}>
 {e.id} {e.name} <button onClick={() => {deleteUser(e.id)}}>Delete</button>

 <input type="text" placeholder='Enter updated ID' onChange={e => setUpdated({...updated,
id:e.target.value})} />
 <input type="text" placeholder='Enter updated Name' onChange={e => setUpdated({...updated,
name:e.target.value})} />
 <button onClick={updateUser}>Update</button>
 </div>
 ))
 }
 </div>
);
}
export default App;