import { render, screen } from '@testing-library/react';
import { describe, expect, it, vi } from 'vitest';
import App from './App';

// The form loads users on mount; keep the test deterministic.
vi.mock('./shared/api', () => ({
  default: {
    get: vi.fn().mockResolvedValue({ data: [] }),
    post: vi.fn().mockResolvedValue({ data: {} }),
    put: vi.fn().mockResolvedValue({ data: {} }),
    delete: vi.fn().mockResolvedValue({ data: {} }),
  },
}));

describe('App', () => {
  it('renders the fill form', () => {
    render(<App />);
    expect(screen.getByRole('heading', { name: /fill/i })).toBeInTheDocument();
    expect(screen.getByPlaceholderText('Enter RegNo')).toBeInTheDocument();
  });
});
