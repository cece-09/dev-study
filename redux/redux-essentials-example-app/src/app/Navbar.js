import React from 'react'
import { useSelector } from 'react-redux'
import { Link } from 'react-router-dom'

export const Navbar = () => {
  const userId = useSelector((state) => state.users.current)
  const isLoggedIn = userId !== null && userId !== undefined
  return (
    <nav>
      <section>
        <h1>Redux Essentials Example</h1>

        <div className="navContent">
          <div className="navLinks">
            <Link to="/">Posts</Link>
            {isLoggedIn ? (
              <Link to="/profile">profile</Link>
            ) : (
              <Link to="/register">Register</Link>
            )}
          </div>
        </div>
      </section>
    </nav>
  )
}
