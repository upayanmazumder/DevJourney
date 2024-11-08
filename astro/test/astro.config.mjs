// @ts-check
import { defineConfig } from 'astro/config';
import deno from '@deno/astro-adapter';

import react from '@astrojs/react';

// https://astro.build/config
export default defineConfig({
  output: 'server',
  adapter: deno(),
  integrations: [react()],
});