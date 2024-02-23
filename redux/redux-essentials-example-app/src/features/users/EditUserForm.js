import { useState } from 'react'
import { useDispatch, useSelector } from 'react-redux'
import { userDeleted, userUpdated } from './userSlice'

export function EditUserForm() {
  const user = useSelector((state) => {
    const userId = state.users.current
    return state.users.users.find((user) => user.id === userId)
  })
  const [name, setName] = useState(user.name ?? '')
  const dispatch = useDispatch()
  const onNameChanged = (e) => setName(e.target.value)
  const onSaveUserClicked = () => {
    dispatch(userUpdated({ id: user.id, name }))
  }
  const onDeleteUserClick = () => {
    dispatch(userDeleted(user.id))
  }

  if (!user) {
    window.location.href = '/'
  }
  return (
    <section>
      <h2>edit profile</h2>
      <label htmlFor="user-name">user name</label>
      <input
        type="text"
        id="user-name"
        name="user-name"
        value={name}
        onChange={onNameChanged}
      />
      <button type="button" onClick={onSaveUserClicked}>
        save
      </button>
      <button type="button" onClick={onDeleteUserClick}>
        delete my account
      </button>
    </section>
  )
}
