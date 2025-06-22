import styles from "./Footer.module.css";
import { useEffect, useState } from "react";
import { FiSun, FiMoon, FiMonitor } from "react-icons/fi";

export default function Footer() {
  const [theme, setTheme] = useState("system");

  const applyTheme = (selected) => {
    if (selected === "system") {
      const prefersDark = window.matchMedia(
        "(prefers-color-scheme: dark)"
      ).matches;
      document.documentElement.setAttribute(
        "data-theme",
        prefersDark ? "dark" : "light"
      );
    } else {
      document.documentElement.setAttribute("data-theme", selected);
    }
  };

  useEffect(() => {
    const stored = localStorage.getItem("theme");
    const initialTheme =
      stored === "light" || stored === "dark" ? stored : "system";
    setTheme(initialTheme);
    applyTheme(initialTheme);

    const media = window.matchMedia("(prefers-color-scheme: dark)");
    const listener = () => {
      if (theme === "system") applyTheme("system");
    };
    media.addEventListener("change", listener);
    return () => media.removeEventListener("change", listener);
  }, [theme]);

  const setAndStoreTheme = (selected) => {
    setTheme(selected);
    localStorage.setItem("theme", selected);
    applyTheme(selected);
  };

  return (
    <footer className={styles.footer}>
      <p>&copy; 2025 | Learning React</p>
      <div className={styles.themeIcons}>
        <button
          onClick={() => setAndStoreTheme("light")}
          className={`${styles.iconButton} ${
            theme === "light" ? styles.active : ""
          }`}
          aria-label="Set light theme"
        >
          <FiSun />
        </button>
        <button
          onClick={() => setAndStoreTheme("dark")}
          className={`${styles.iconButton} ${
            theme === "dark" ? styles.active : ""
          }`}
          aria-label="Set dark theme"
        >
          <FiMoon />
        </button>
        <button
          onClick={() => setAndStoreTheme("system")}
          className={`${styles.iconButton} ${
            theme === "system" ? styles.active : ""
          }`}
          aria-label="Use system theme"
        >
          <FiMonitor />
        </button>
      </div>
    </footer>
  );
}
