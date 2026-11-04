/* FUN_80162710
 * image   ovl_008bef8 (ovl), base 0x80161cf0
 * address 0x80162710  body 0x80162710..0x8016273b  size 44 B
 * body sha256 ffd68fd144518b0ccb274a302ce5f0703e1710fbb31cf7fc6658eee4b929492e
 * provider record sha256 54d382fa7a875a8538a4f4dada3be7c01887b976af33037bf2798bf056eb8615
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80162710(int param_1)

{
  if (*(char *)(param_1 + 6) == '\0') {
    func_0x80036c68(param_1,0,0x20,0);
  }
  return;
}
