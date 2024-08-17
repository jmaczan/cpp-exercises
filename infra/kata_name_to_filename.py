def kata_name_to_filename(
    kata_name: str, prefix="src/", extension=".cpp", create_file=True
):
    import os

    filename = (
        prefix
        + kata_name.lower()
        .replace(" ", "_")
        .replace("'", "")
        .replace('"', "")
        .replace(".", "")
        .replace(",", "")
        + extension
    )

    try:
        with open(filename, "x") as f:
            print(f"File {filename} created")
    except FileExistsError:
        print("File exists")
        print(filename)


if __name__ == "__main__":
    import argparse

    parser = argparse.ArgumentParser()
    parser.add_argument("kata_name", type=str)
    args = parser.parse_args()
    kata_name_to_filename(args.kata_name)
