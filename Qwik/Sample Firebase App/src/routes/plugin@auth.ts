import { FirestoreAdapter } from "@auth/firebase-adapter";
import { QwikAuth$ } from "@auth/qwik";
import Google from "@auth/qwik/providers/google";
import { cert, initializeApp, getApps } from "firebase-admin/app";
import { getFirestore } from "firebase-admin/firestore";

// Initialize Firebase if not already initialized
const firebaseAdminInit = () => {
  if (!getApps().length) {
    initializeApp({
      credential: cert({
        projectId: process.env.AUTH_FIREBASE_PROJECT_ID,
        clientEmail: process.env.AUTH_FIREBASE_CLIENT_EMAIL,
        privateKey: process.env.AUTH_FIREBASE_PRIVATE_KEY?.replace(/\\n/g, '\n') || '', // Handle private key line breaks
      }),
    });
  }
};

export const { onRequest, useSession, useSignIn, useSignOut } = QwikAuth$(
  () => {
    firebaseAdminInit(); // Initialize Firebase Admin SDK
    const firestore = getFirestore();

    return {
      providers: [
        Google({
          clientId: process.env.AUTH_GOOGLE_ID,
          clientSecret: process.env.AUTH_GOOGLE_SECRET,
        }),
      ],
      adapter: FirestoreAdapter({
        firestore,
      }),
    };
  },
);