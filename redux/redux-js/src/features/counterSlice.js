import { createSlice } from "@reduxjs/toolkit";


// createSlice function
// name의 문자열에 reducer의 함수명을 붙여서 reducer 함수 객체 생성 후 반환
// ex. counter/increment 이런 식이다.
// 또한, 자동으로 action creators를 생성한다 (reducer 함수와 동일한 이름으로)
export const counterSlice = createSlice({
    name: 'counter',
    initialState: {
        value: 0
    },
    reducers: {
        increment: state => {
            // Redux Toolkit은 reducer 안에서 "변경 mutating" 로직을 작성하도록 허용한다.
            // immer library를 사용하기 때문에, 상태를 실제로 변경하는 것은 아니다.
            // 라이브러리는 'draft state'로부터 변경을 감지하고
            // 새로운 immutable한 상태를 이 변경에 기반하여 생성한다. (불변성)

            // Immer Library? 변경사항을 자동으로 트래킹하는 라이브러리
            // Proxy라는 JS툴을 사용해서, 제공된 데이터를 래핑한 뒤, 래핑된 것을 변경하는 코드를 작성할 수 있도록 한다.
            // 그래서 안전하게 immutable한 방식으로 값을 갱신할 수 있다.
            // Immer Library는 createSlice함수 안에서 지원되므로 이 안에서만 데이터를 변경하면 된다.
            state.value += 1
        },
        decrement: state => {
            state.value -= 1
        },
        incrementByAmount: (state, action) => {
            state.value += action.payload
        }
    }
})

export const selectCount = state => state.counter.value
export const {increment, decrement, incrementByAmount} = counterSlice.actions
export default counterSlice.reducer