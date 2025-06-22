// components/Header.tsx
import styles from "./Header.module.css";

export default function Header() {
  return (
    <header className={styles.header}>
      <h1 className={styles.logo}>Learning React</h1>
      <nav>
        <ul className={styles.navList}>
          <li>
            <a href="/" className={styles.navLink}>
              Home
            </a>
          </li>
          <li>
            <a href="/about" className={styles.navLink}>
              About
            </a>
          </li>
        </ul>
      </nav>
    </header>
  );
}
