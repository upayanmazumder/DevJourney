import { component$ } from "@builder.io/qwik";
import type { DocumentHead } from "@builder.io/qwik-city";

export default component$(() => {
  return (
    <>
      <div class="container container-center container-spacing-xl">
        <h3>You are not signed in!</h3>
        <br/>
        <p>The content you are trying to</p>
        <p>access requires you to be logged in!</p>
      </div>
    </>
  );
});

export const head: DocumentHead = {
  title: "Not signed in!",
};