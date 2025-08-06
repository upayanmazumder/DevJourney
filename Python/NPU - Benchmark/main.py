import onnxruntime as ort
import numpy as np
import time

# Update this with your ONNX model path
MODEL_PATH = r"C:\Users\upaya\Downloads\fasterrcnn_mobilenet_v3_large_320_fpn_Opset16.onnx"

def summarize_provider(session):
    try:
        providers = session.get_providers()
        print("ONNXRuntime Providers available:", providers)
        prefer = session.get_provider_options()
        print("Provider options:", prefer)
    except Exception as e:
        print("Provider info unavailable:", e)

def get_input_details(session):
    input_meta = session.get_inputs()[0]
    name = input_meta.name
    shape = [d if isinstance(d, int) else 1 for d in input_meta.shape]  # Set undefined dims to 1
    dtype = np.float32 if input_meta.type == 'tensor(float)' else None
    return name, shape, dtype

def benchmark(session, input_name, dummy_input, runs=10):
    # Warmup
    for _ in range(3):
        session.run(None, {input_name: dummy_input})
    # Timed runs
    start = time.perf_counter()
    for _ in range(runs):
        output = session.run(None, {input_name: dummy_input})
    elapsed = time.perf_counter() - start
    print(f"Avg inference time ({session.get_providers()[0]}): {elapsed/runs:.4f}s")
    return output

def main():
    providers = [
        ('DmlExecutionProvider', {'device_id': 0}),
        'CPUExecutionProvider'
    ]
    for provider in providers:
        print(f"\nTrying provider: {provider}")
        try:
            session = ort.InferenceSession(
                MODEL_PATH,
                providers=[provider] if isinstance(provider, str) else [provider[0]],
                provider_options=[provider[1]] if isinstance(provider, tuple) else None
            )
            summarize_provider(session)
            input_name, input_shape, input_dtype = get_input_details(session)
            dummy_input = np.random.rand(*input_shape).astype(input_dtype)

            output = benchmark(session, input_name, dummy_input)
            print(f"Output type/len: {type(output)}, {[o.shape if hasattr(o, 'shape') else type(o) for o in output]}")
        except Exception as e:
            print(f"Error with provider {provider}: {e}")

if __name__ == "__main__":
    main()
