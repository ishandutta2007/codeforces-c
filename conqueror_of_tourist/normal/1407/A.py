for s in[*open(0)][2::2]:r='0'.join(x[len(x)%2:]for x in s[::2].split('0'));print(len(r),*r)