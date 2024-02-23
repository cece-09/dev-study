import { useDispatch, useSelector } from "react-redux"
import { decrement, increment, selectCount } from "./counterSlice"
import { useState } from "react"

export default function Counter() {
    const count = useSelector(selectCount)
    const dispatch = useDispatch()
    const [incrementAmount, setIncrementAmount] = useState('2')

    return (
        <div>
            <button onClick={() => dispatch(increment())}>+</button>
            <div>{count}</div>
            <button onClick={() => dispatch(decrement())}>-</button>
        </div>
    )

}