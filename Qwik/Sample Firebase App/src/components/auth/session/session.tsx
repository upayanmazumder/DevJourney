import { component$ } from '@builder.io/qwik';
import { useSession, useSignIn } from '~/routes/plugin@auth';
import sessionStyles from "./session.module.css";
import { Form } from '@builder.io/qwik-city';
import { BsGoogle } from "@qwikest/icons/bootstrap";
import unknownPerson from "../../../media/authentication/unknown-person.png"
export default component$(() => {
  const session = useSession();
  const signIn = useSignIn();


  // Check if the user is signed in
  const isSignedIn = session.value?.user;

  return (
    <div class={sessionStyles.container}>
      {isSignedIn ? (
        <>
          <a href="/profile">
            <div class={sessionStyles.imgContainer}>
              <img 
                class={sessionStyles.img}
                src={session.value.user?.image ?? unknownPerson} 
                loading="lazy"  
                alt={session.value.user?.name ?? 'User Icon'} 
                width="80" 
                height="80" 
              />
            </div>
          </a>
          <div class={sessionStyles.userInfo}>
            <p>{session.value.user?.name}</p>
            <p>{session.value.user?.email}</p>
          </div>
          

        </>
      ) : (
        <Form action={signIn} class={sessionStyles.form}>
          <input type="hidden" name="providerId" value="google" />
          <input type="hidden" name="options.redirectTo" value="/a/signedin" />
          <button class={sessionStyles.iconButton}>
            <BsGoogle />
          </button>
        </Form>
      )}
    </div>
  );
});
