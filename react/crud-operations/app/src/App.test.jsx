import { render, screen } from '@testing-library/react';
import { describe, expect, it, vi } from 'vitest';
import App from './App';

// The dashboard fetches students on mount; keep the test deterministic.
vi.mock('./shared/axios', () => ({
  default: {
    get: vi.fn().mockResolvedValue({ data: [] }),
    post: vi.fn().mockResolvedValue({ data: {} }),
    put: vi.fn().mockResolvedValue({ data: {} }),
    delete: vi.fn().mockResolvedValue({ data: {} }),
  },
}));

describe('App', () => {
  it('renders the marks entry form', () => {
    render(<App />);
    expect(
      screen.getByRole('heading', { name: /student marks entry/i }),
    ).toBeInTheDocument();
    expect(screen.getByPlaceholderText('REGNO')).toBeInTheDocument();
  });
});
