import { Router } from 'express';

const router = Router();

router.get('/', (req, res) => {
  const htmlContent = `
    <!DOCTYPE html>
    <html>
      <head>
        <title>TypeScript Site</title>
        <style>
          body {
            font-family: Arial, sans-serif;
            background-color: #f4f4f4;
            margin: 0;
            padding: 0;
            display: flex;
            justify-content: center;
            align-items: center;
            height: 100vh;
          }
          .container {
            background-color: #fff;
            padding: 20px;
            border-radius: 8px;
            box-shadow: 0 0 10px rgba(0, 0, 0, 0.1);
            text-align: center;
          }
          h1 {
            color: #333;
          }
          p {
            color: #666;
          }
        </style>
      </head>
      <body>
        <div class="container">
          <h1>Hello, TypeScript!</h1>
          <p>Welcome to your TypeScript sites.</p>
        </div>
      </body>
    </html>
  `;
  res.send(htmlContent);
});

export default router;