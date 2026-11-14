import { render, screen } from '@testing-library/react';
import { describe, expect, it } from 'vitest';
import App from './App';

describe('App', () => {
  it('renders the home route', () => {
    render(<App />);
    expect(
      screen.getByRole('heading', { name: /home page/i }),
    ).toBeInTheDocument();
  });
});
