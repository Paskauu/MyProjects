import './App.css'
import Student from "./Student.tsx"

function App() {
  return (
    <div className='Page'>
      <Student Name="Caio Covre Pascoal" Age={20} IsStudent/>
      <Student/>
    </div>
  )
}

export default App
