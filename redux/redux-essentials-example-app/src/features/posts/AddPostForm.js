import { useState } from 'react'
import { useDispatch, useSelector } from 'react-redux'
import { postAdded } from './postSlice'

export const AddPostForm = () => {
  const [title, setTitle] = useState('')
  const [content, setContent] = useState('')

  const userId = useSelector((state) => state.users.current)
  const dispatch = useDispatch()

  const onTitleChanged = (e) => setTitle(e.target.value)
  const onContentChanged = (e) => setContent(e.target.value)

  const onSavePostClicked = () => {
    if (title && content) {
      dispatch(
        postAdded(
          // postSlice의 reducer쪽에
          // prepare로 nanoid를 추가하도록 설정
          // 따라서 title, content만 념겨준다
          title,
          content,
          userId,
        ),
      )
      setTitle('')
      setContent('')
    }
  }

  if (!userId) return <></>

  return (
    <section>
      <h2>New Post</h2>
      <label htmlFor="post-title">Post Title</label>
      <input
        type="text"
        id="post-title"
        name="post-title"
        value={title}
        onChange={onTitleChanged}
      />
      <textarea
        id="post-content"
        name="post-content"
        value={content}
        onChange={onContentChanged}
      />
      <button type="button" onClick={onSavePostClicked}>
        save post
      </button>
    </section>
  )
}
