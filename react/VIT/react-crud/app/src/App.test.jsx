import { render, screen } from '@testing-library/react';
import { describe, expect, it, vi } from 'vitest';
import App from './App';

// App loads the user list from the API on mount.
vi.mock('axios', () => ({
  default: {
    get: vi.fn().mockResolvedValue({ data: [] }),
    post: vi.fn().mockResolvedValue({ data: {} }),
    put: vi.fn().mockResolvedValue({ data: {} }),
    delete: vi.fn().mockResolvedValue({ data: {} }),
  },
}));

describe('App', () => {
  it('renders the user entry controls', () => {
    render(<App />);
    expect(screen.getByPlaceholderText('Enter ID...')).toBeInTheDocument();
    expect(screen.getByPlaceholderText('Enter Name...')).toBeInTheDocument();
    expect(screen.getByRole('button', { name: /^add$/i })).toBeInTheDocument();
  });
});
