import { useState } from "react"
import { useDispatch, useSelector } from "react-redux"
import { useHistory } from "react-router-dom/cjs/react-router-dom.min"
import { postUpdated } from "./postSlice"

export const EditPostForm = ({match}) => {
    const {postId} = match.params
    const post = useSelector(state =>
        state.posts.find(post => post.id === postId)
    )

    const [title, setTitle] = useState(post.title ?? '')
    const [content, setContent] = useState(post.content ?? '')
    const dispatch = useDispatch()
    const history = useHistory()

    const onTitleChanged = e => setTitle(e.target.value)
    const onContentChanged = e => setContent(e.target.value)
    const onSavePostClicked = () => {
        if(title && content) {
            dispatch(postUpdated({id: postId, title, content}))
            history.push(`/post/${postId}`)
        }
    }

    if(!post) return <div>post not found</div>

    return <section>
        <h2>edit post</h2>
        <label htmlFor="post-title">post title</label>
        <input type='text' id="post-title" name="post-title" value={title} onChange={onTitleChanged} />
        <label htmlFor="post-content">post content</label>
        <textarea id="post-content" name="post-content" value={content} onChange={onContentChanged} />
        <button disabled={title === post.title && content === post.content} type="button" onClick={onSavePostClicked}>change</button>
    </section>
}