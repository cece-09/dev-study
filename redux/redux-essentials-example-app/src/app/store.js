import { configureStore } from '@reduxjs/toolkit'
import postsReducer from '../features/posts/postSlice'
import usersReducer from '../features/users/userSlice'

export const store = configureStore({
  reducer: {
    users: usersReducer,
    posts: postsReducer,
  },
})
