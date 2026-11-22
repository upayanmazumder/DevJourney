import assert from 'node:assert/strict';
import { spawnSync } from 'node:child_process';
import {
  copyFileSync,
  mkdtempSync,
  mkdirSync,
  readdirSync,
  readFileSync,
  rmSync,
} from 'node:fs';
import { tmpdir } from 'node:os';
import { dirname, join } from 'node:path';
import { fileURLToPath } from 'node:url';

// Every source defines Main, so compile each program in its own temporary directory.
const root = dirname(fileURLToPath(import.meta.url));
const temp = mkdtempSync(join(tmpdir(), 'acc-verify-'));
const programs = new Map();
const exercised = new Set();
let checks = 0;

function command(executable, args, input = '') {
  const result = spawnSync(executable, args, {
    input,
    encoding: 'utf8',
    timeout: 15000,
    maxBuffer: 16 * 1024 * 1024,
  });
  assert.equal(result.error, undefined, `${executable}: ${result.error}`);
  assert.equal(
    result.status,
    0,
    `${executable} ${args.join(' ')}\n${result.stderr}`,
  );
  return result.stdout.replaceAll('\r', '');
}

function run(key, input) {
  assert.ok(programs.has(key), `Unknown program: ${key}`);
  exercised.add(key);
  return command('java', ['-cp', programs.get(key), 'Main'], `${input}\n`);
}

const tokens = (text) =>
  String(text).trim().split(/\s+/).filter(Boolean).join(' ');
function check(key, input, expected, exact = false) {
  const actual = run(key, input);
  assert.equal(
    exact ? actual.trimEnd() : tokens(actual),
    exact ? String(expected).trimEnd() : tokens(expected),
    `${key}, input ${JSON.stringify(input)}`,
  );
  checks++;
}

function primes(lo, hi) {
  const result = [];
  for (let n = Math.max(2, lo); n <= hi; n++) {
    let prime = true;
    for (let p = 2; p <= n / p; p++) {
      if (n % p === 0) {
        prime = false;
        break;
      }
    }
    if (prime) result.push(n);
  }
  return result.join(' ');
}

function maxProduct(a) {
  let best = BigInt(a[0]);
  for (let i = 0; i < a.length; i++) {
    let product = 1n;
    for (let j = i; j < a.length; j++) {
      product *= BigInt(a[j]);
      if (product > best) best = product;
    }
  }
  return best;
}

function equilibrium(a) {
  const sums = a
    .map((_, i) => [
      a.slice(0, i).reduce((s, x) => s + BigInt(x), 0n),
      a.slice(i + 1).reduce((s, x) => s + BigInt(x), 0n),
    ])
    .filter(([l, r]) => l === r)
    .map(([l]) => l);
  return sums.length ? sums.reduce((a, b) => (a > b ? a : b)) : 0n;
}

function longestPalindrome(s) {
  let best = '';
  for (let i = 0; i < s.length; i++) {
    for (let j = i + 1; j <= s.length; j++) {
      const part = s.slice(i, j);
      if (
        part.length > best.length &&
        part === part.split('').reverse().join('')
      )
        best = part;
    }
  }
  return best;
}

function validateQueens(n, count) {
  const output = run('FAT/21', String(n));
  const boards = output.trim().split(/\n\s*\n/);
  assert.equal(boards.length, count);
  const seen = new Set();
  for (const board of boards) {
    const rows = board
      .split('\n')
      .map((r) => r.trim().split(/\s+/).map(Number));
    assert.equal(rows.length, n);
    const columns = rows.map((row) => {
      assert.equal(row.length, n);
      assert.ok(row.every((v) => v === 0 || v === 1));
      assert.equal(
        row.reduce((s, v) => s + v, 0),
        1,
      );
      return row.indexOf(1);
    });
    for (let i = 0; i < n; i++)
      for (let j = 0; j < i; j++) {
        assert.notEqual(columns[i], columns[j]);
        assert.notEqual(Math.abs(columns[i] - columns[j]), i - j);
      }
    assert.ok(!seen.has(columns.join(',')));
    seen.add(columns.join(','));
  }
  checks++;
}

try {
  for (const scope of ['CAT-2', 'FAT']) {
    for (const file of readdirSync(join(root, scope))
      .filter((f) => f.endsWith('.java'))
      .sort()) {
      const key = `${scope}/${file.slice(0, 2)}`;
      const target = join(temp, scope, file.slice(0, 2));
      mkdirSync(target, { recursive: true });
      copyFileSync(join(root, scope, file), join(target, 'Main.java'));
      command('javac', ['-d', target, join(target, 'Main.java')]);
      programs.set(key, target);
    }
  }
  assert.equal(programs.size, 35);

  for (const [a, b] of [
    [14, 6],
    [-7, 9],
    [-2147483648, -1],
    [-2147483648, -2147483648],
    [2147483647, 2147483647],
    [0, -5],
  ]) {
    check('CAT-2/01', `${a} ${b}`, BigInt(a) * BigInt(b));
  }
  for (const [input, expected] of [
    ['48 18', 6],
    ['0 0', 0],
    ['-42 56', 14],
    ['-9223372036854775808 0', '9223372036854775808'],
  ])
    check('CAT-2/02', input, expected);
  for (const [a, b] of [
    ['1234', '5678'],
    ['-1234', '5678'],
    ['9223372036854775807', '9223372036854775807'],
    ['0', '-99'],
  ])
    check('CAT-2/03', `${a} ${b}`, BigInt(a) * BigInt(b));
  for (const x of [0, 1, 15, 75, 1775, -1, -2147483648, 0x55555555]) {
    const bits = (x >>> 0).toString(2).padStart(32, '0');
    let best = 0;
    for (let i = 0; i < 32; i++) {
      const changed = bits.slice(0, i) + '1' + bits.slice(i + 1);
      best = Math.max(best, ...changed.split('0').map((s) => s.length));
    }
    check('CAT-2/04', String(x), best);
  }
  for (const x of [0, 1, 100, 255])
    check('CAT-2/05', String(x), (x % 16) * 16 + Math.floor(x / 16));
  for (const a of [[], [1], [1, 2, 3, 4, 5, 6, 7]]) {
    for (const d of [-9, 0, 2, 7, 14]) {
      const r = a.length ? ((d % a.length) + a.length) % a.length : 0;
      const expected = [...a.slice(r), ...a.slice(0, r)].join(' ');
      for (const key of ['CAT-2/06', 'FAT/23'])
        check(key, `${a.length} ${d} ${a.join(' ')}`, expected);
    }
  }
  for (const a of [
    [2, 3, -2, 4],
    [-2, 0, -1],
    [-2, -3, -4],
    [0],
    ['9223372036854775807', 2],
    [-1, 2, -3, 0, 4, -5, -6],
  ])
    check('CAT-2/07', `${a.length} ${a.join(' ')}`, maxProduct(a));
  for (const x of [-1, 1, 2147483647])
    check('CAT-2/08', Array(36).fill(x).join(' '), BigInt(x) * 7n);
  for (const a of [
    [1, 2, 3, 4, 5, 4, 3, 2, 1],
    [1, 2],
    [-1, 0, -1],
    ['-9223372036854775808', 0, '-9223372036854775808'],
    ['9223372036854775807', 0, '9223372036854775807'],
    [],
  ])
    check('CAT-2/09', `${a.length} ${a.join(' ')}`, equilibrium(a));
  check('CAT-2/10', '6 16 17 4 3 5 2', '17 5 2');
  check('CAT-2/10', '3 5 5 5', '5 5 5');
  check('CAT-2/10', '0', '');
  check('CAT-2/11', '7 1 1 2 1 3 5 1', '1');
  check('CAT-2/11', '4 1 2 3 4', '-1');
  check('CAT-2/11', '0', '-1');
  for (const input of ['aabb', 'abc', 'malayalam', '\u0100\u0100b', '😀😀a']) {
    const counts = new Map();
    for (const c of input) counts.set(c, (counts.get(c) || 0) + 1);
    const odds = [...counts].filter(([, n]) => n % 2);
    const half = [...counts]
      .sort(([a], [b]) => a.codePointAt(0) - b.codePointAt(0))
      .map(([c, n]) => c.repeat(Math.floor(n / 2)))
      .join('');
    const palindrome =
      odds.length > 1
        ? 'Not possible'
        : half + (odds[0]?.[0] || '') + Array.from(half).reverse().join('');
    check('CAT-2/12', input, palindrome, true);
  }

  for (const n of [0, 1, 2, 30, 97]) check('FAT/01', String(n), primes(2, n));
  for (const [lo, hi] of [
    [-5, 30],
    [1, 1],
    [14, 16],
    [90, 140],
    [2147483600, 2147483647],
  ])
    check('FAT/02', `${lo} ${hi}`, primes(lo, hi));
  for (const n of [1, 2, 9, 48, 97]) {
    let count = 0;
    for (let x = 1; x <= n; x++) {
      let a = x,
        b = n;
      while (b) [a, b] = [b, a % b];
      if (a === 1) count++;
    }
    check('FAT/03', String(n), count);
  }
  for (const [input, expected] of [
    ['3 3 2 4 3 5 1', 11],
    ['2 4 2 6 4', 10],
    ['2 2 1 4 2', 'No solution'],
    ['2 1 0 7 -1', 6],
    ['2 4 0 6 0', 0],
  ])
    check('FAT/04', input, expected);
  for (const [input, expected] of [
    ['69', true],
    ['18081', true],
    ['962', false],
    ['2', false],
    ['0', true],
  ])
    check('FAT/05', input, expected);
  check('FAT/06', '1', '0 1 8');
  check('FAT/06', '2', '11 69 88 96');
  const strobo = [];
  const rotateDigit = { 0: '0', 1: '1', 6: '9', 8: '8', 9: '6' };
  for (let x = 100; x < 1000; x++)
    if (
      String(x)
        .split('')
        .reverse()
        .map((c) => rotateDigit[c] || '?')
        .join('') === String(x)
    )
      strobo.push(x);
  check('FAT/06', '3', strobo.join(' '));
  for (const n of [0n, 1n, 9n, 10n, 17n, 9223372036854775807n]) {
    const b = n.toString(2);
    check('FAT/07', String(n), b === b.split('').reverse().join(''));
  }
  for (const [input, expected] of [
    ['0', 0],
    ['9', 3],
    ['15', 3],
    ['16', 4],
    ['9223372036854775807', '3037000499'],
  ])
    check('FAT/08', input, expected);
  for (const n of [0n, 1n, 13n, 1000000000n, 9223372036854775807n]) {
    const perimeter = BigInt(run('FAT/09', String(n)).trim());
    assert.equal(perimeter % 8n, 0n);
    const r = perimeter / 8n;
    const apples = (x) => 2n * x * (x + 1n) * (2n * x + 1n);
    assert.ok(apples(r) >= n);
    assert.ok(r === 0n || apples(r - 1n) < n);
    checks++;
  }
  check(
    'FAT/10',
    '5\nfile10\nfile2\nfile1\nfile02\nfile2a',
    'file1\nfile2\nfile2a\nfile02\nfile10',
    true,
  );
  check(
    'FAT/10',
    '3\nx999999999999999999999\nx2\nx10',
    'x2\nx10\nx999999999999999999999',
    true,
  );
  check(
    'FAT/11',
    '4 3 Ram 19 2 Mohan 20 4 Ram 18 1 Ram 18',
    '2 Mohan 20\n1 Ram 18\n4 Ram 18\n3 Ram 19',
    true,
  );
  for (const a of [[], [3, -1, 3, 0, 7], [5, 4, 3, 2, 1]])
    for (const key of ['FAT/12', 'FAT/13'])
      check(
        key,
        `${a.length} ${a.join(' ')}`,
        [...a].sort((a, b) => a - b).join(' '),
      );
  const ordered = Array.from({ length: 10000 }, (_, i) => i);
  check('FAT/12', `${ordered.length} ${ordered.join(' ')}`, ordered.join(' '));
  for (const s of ['', 'FACE-PREP', 'a -b-- c'])
    check(
      'FAT/14',
      s,
      '-'.repeat(s.split('-').length - 1) + s.replaceAll('-', ''),
      true,
    );
  for (const s of [
    '',
    'abba',
    'babad',
    'abcababacs',
    'a#$@a',
    '#@$',
    'a b a',
    'abacaba',
  ])
    check('FAT/15', s, longestPalindrome(s), true);
  check('FAT/16', 'ABB', 'ABB\nBAB\nBBA', true);
  check('FAT/16', '', '', true);
  check('FAT/17', '3 1 2 3 2', '1 2\n1 3\n2 3', true);
  check('FAT/17', '3 1 1 2 2', '1 1\n1 2\n1 2', true);
  check('FAT/17', '0 0', '', true);
  check('FAT/17', '2 1 2 3', '', true);
  for (const [n, k] of [
    [14, 2n],
    [1, 7n],
    [5, 9223372036854775807n],
  ]) {
    const circle = Array.from({ length: n }, (_, i) => i + 1);
    let index = 0n;
    while (circle.length > 1) {
      index = (index + k - 1n) % BigInt(circle.length);
      circle.splice(Number(index), 1);
    }
    check('FAT/18', `${n} ${k}`, circle[0]);
  }
  for (const [r, c] of [
    [1, 7],
    [3, 3],
    [20, 20],
    [30, 30],
  ]) {
    let combinations = 1n;
    for (let i = 1; i < r; i++)
      combinations = (combinations * BigInt(c - 1 + i)) / BigInt(i);
    check('FAT/19', `${r} ${c}`, combinations);
  }
  check('FAT/20', '1 0', 'No solution');
  check('FAT/20', '1 1', '1');
  check(
    'FAT/20',
    '4 1 0 0 1 1 0 1 0 1 1 1 1 0 1 0 1',
    '1 0 0 0\n1 0 0 0\n1 1 1 1\n0 0 0 1',
    true,
  );
  check('FAT/21', '2', 'No solution');
  validateQueens(4, 2);
  validateQueens(5, 10);
  check('FAT/22', '1 0 0', '1');
  check('FAT/22', '2 0 0', 'No tour found');
  for (const [n, row, col] of [
    [8, 0, 0],
    [5, 0, 0],
    [6, 0, 0],
    [7, 0, 0],
    [8, 3, 3],
  ]) {
    const board = run('FAT/22', `${n} ${row} ${col}`).trim().split('\n');
    assert.equal(board.length, n);
    assert.ok(board.every((r) => r.trim().split(/\s+/).length === n));
    const tour = board.join(' ').split(/\s+/).map(Number);
    assert.equal(tour.length, n * n);
    assert.equal(new Set(tour).size, n * n);
    assert.equal(tour[row * n + col], 1);
    const positions = [];
    tour.forEach((v, i) => {
      assert.ok(Number.isInteger(v) && v >= 1 && v <= n * n);
      positions[v] = [Math.floor(i / n), i % n];
    });
    for (let i = 2; i <= n * n; i++) {
      const dr = Math.abs(positions[i][0] - positions[i - 1][0]);
      const dc = Math.abs(positions[i][1] - positions[i - 1][1]);
      assert.equal(dr * dc, 2);
    }
    checks++;
  }
  const examples = JSON.parse(
    readFileSync(join(root, 'examples.json'), 'utf8'),
  );
  for (const { scope, file, input, expected } of examples) {
    const key = `${scope}/${file.slice(0, 2)}`;
    if (scope === 'FAT') {
      assert.equal(
        run(key, input),
        expected,
        `${key}, documented input ${JSON.stringify(input)}`,
      );
      checks++;
    } else {
      check(key, input, expected);
    }
  }
  assert.equal(exercised.size, programs.size);
  console.log(
    `PASS: ${programs.size} programs compiled, ${checks} independent output and board checks passed.`,
  );
} finally {
  rmSync(temp, { recursive: true, force: true });
}
