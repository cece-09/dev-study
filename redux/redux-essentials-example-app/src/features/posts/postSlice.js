import { createSlice, nanoid } from '@reduxjs/toolkit'

const initialState = [
  { id: '1', title: 'Post1', content: 'content1', userId: '1' },
  { id: '2', title: 'Post2', content: 'content2', userId: '2' },
  { id: '3', title: 'Post3', content: 'content3', userId: '3' },
]

const postSlice = createSlice({
  name: 'posts',
  initialState,
  reducers: {
    postAdded: {
      reducer(state, action) {
        state.push(action.payload)
      },
      // post add 시 항상 공통적으로 일어나야 하는 로직
      // 따라서 prepare로 id필드를 채워준다.
      // ! reducer 함수 안에서는 절대 임의값을 쓰지 않는다 !
      prepare(title, content, userId) {
        return {
          payload: {
            id: nanoid(),
            title,
            content,
            userId,
          },
        }
      },
    },
    postUpdated(state, action) {
      // find post to update
      const post = state.find((p) => p.id === action.payload.id)
      if (!post) return
      // change properties
      post.title = action.payload.title
      post.content = action.payload.content
      post.userId = action.payload.userId
    },
    postDeleted(state, action) {
      // 다음 상태를 반환하는 로직 짜기
      return state.filter(({ id }) => id !== action.payload)
    },
  },
})

export const { postAdded, postUpdated, postDeleted } = postSlice.actions
export default postSlice.reducer
