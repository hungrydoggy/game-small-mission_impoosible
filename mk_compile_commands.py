import json
import re
import sys

def filter_compile_commands(input_path, output_path, patterns):
  with open(input_path, 'r', encoding='utf-8') as f:
    data = json.load(f)

  pattern = re.compile('|'.join(re.escape(p) for p in patterns))

  filtered_data = [entry for entry in data if pattern.search(entry.get('output', ''))]

  with open(output_path, 'w', encoding='utf-8') as f:
    json.dump(filtered_data, f, indent=2)

if __name__ == "__main__":
  if len(sys.argv) < 3:
    print("Usage: python filter_compile_commands.py <input_json> <target1> [<target2> ...]")
    sys.exit(1)

  input_path = sys.argv[1]
  output_path = "compile_commands.json"
  targets = sys.argv[2:]

  filter_compile_commands(input_path, output_path, targets)
