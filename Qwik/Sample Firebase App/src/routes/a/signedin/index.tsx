import { component$ } from "@builder.io/qwik";
import type { DocumentHead } from "@builder.io/qwik-city";

export default component$(() => {
  return (
    <>
      <div class="container container-center container-spacing-xl">
        <h3>Signed in!</h3> <br/>
        <p>You are now signed in!</p>
      </div>
    </>
  );
});

export const head: DocumentHead = {
  title: "Signed In Successfully!",
  meta: [
    {
      name: "description",
      content: "Congratulations on signing in"
    }
  ]
};