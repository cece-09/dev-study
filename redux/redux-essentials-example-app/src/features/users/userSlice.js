// User feature는 직접 짜보자
// 1. 유저 CRUD 기능
// 2. 포스트에 저자 추가

import { createSlice, nanoid } from '@reduxjs/toolkit'

const SIGN_OUT = null

const initialState = {
  current: SIGN_OUT,
  users: [
    { id: '0', name: 'pikachu' },
    { id: '1', name: 'ggobugi' },
    { id: '2', name: 'jamanbo' },
  ],
}

const userSlice = createSlice({
  name: 'users',
  initialState,
  reducers: {
    userAdded: {
      reducer(state, action) {
        state.users.push(action.payload)
        state.current = action.payload.id // 현재 유저로 설정
      },
      prepare(name) {
        return {
          payload: {
            id: nanoid(),
            name,
          },
        }
      },
    },
    userUpdated(state, action) {
      const { id, name } = action.payload
      const user = state.users.find((u) => u.id === id)
      if (!user) return
      user.name = name
    },
    userDeleted(state, action) {
      state.users = state.users.filter(({ id }) => id === action.payload)
    },
  },
})

export const { userAdded, userUpdated, userDeleted } = userSlice.actions
export default userSlice.reducer
