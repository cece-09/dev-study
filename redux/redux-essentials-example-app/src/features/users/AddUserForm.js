import { useState } from 'react'
import { useDispatch } from 'react-redux'
import { userAdded } from './userSlice'

export function AddUserForm() {
  const [name, setName] = useState('')
  const dispatch = useDispatch()

  const onNameChanged = (e) => setName(e.target.value)
  const onSaveUserClicked = () => {
    if (name) {
      dispatch(userAdded(name))
    } else {
      alert('please enter username')
    }
  }

  return (
    <section>
      <h2>register</h2>
      <label htmlFor="user-name">user name</label>
      <input
        type="text"
        id="user-name"
        name="user-name"
        value={name}
        onChange={onNameChanged}
      />
      <button type="button" onClick={onSaveUserClicked}>
        create account
      </button>
    </section>
  )
}
