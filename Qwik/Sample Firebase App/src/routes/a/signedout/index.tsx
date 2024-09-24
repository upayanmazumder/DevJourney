import { component$ } from "@builder.io/qwik";
import type { DocumentHead } from "@builder.io/qwik-city";

export default component$(() => {
  return (
    <>
      <div class="container container-center container-spacing-xl">
        <h3>Signed out!</h3>
        <p>You are now signed out!</p>
      </div>
    </>
  );
});

export const head: DocumentHead = {
  title: "Signed Out Successfully!",
};