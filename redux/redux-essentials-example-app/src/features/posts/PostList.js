import React from 'react'
import { useDispatch, useSelector } from 'react-redux'
import { postDeleted } from './postSlice'
import { Link } from 'react-router-dom'

export const PostList = () => {
  const posts = useSelector((state) => state.posts)
  const dispatch = useDispatch()
  const onPostDeleteClicked = (id) => {
    dispatch(postDeleted(id))
  }
  const renderedPost = posts.map(({ id, title, content, userId }) => {
    const users = useSelector((state) => state.users)
    const author = users.users.find((user) => user.id === userId) ?? null
    return (
      <article className="post-excerpt" key={id}>
        <h3>{title}</h3>
        <p className="post-content">{content.substring(0, 100)}</p>
        <p>{author?.name ?? 'user not found'}</p>
        <Link to={`/posts/${id}`} className="button muted-button">
          view post
        </Link>
        <Link to={`/posts/${id}/edit`} className="button muted-button">
          edit post
        </Link>
        <button type="button" onClick={() => onPostDeleteClicked(id)}>
          delete
        </button>
      </article>
    )
  })

  return (
    <section className="post-list">
      <h2>posts</h2>
      {renderedPost}
    </section>
  )
}
