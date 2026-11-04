/* FUN_80165ae0
 * image   ovl_0098ee0 (ovl), base 0x80161cf0
 * address 0x80165ae0  body 0x80165ae0..0x80165b43  size 100 B
 * body sha256 00fd20ffd01513763a13c4c664c2e8c72cce55c13a15ca947dda64283200baf7
 * provider record sha256 be970e543bd52955d68834b6c985f80d0a26dba96b62657379df16574aedd4e4
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80165ae0(int param_1)

{
  char cVar1;
  
  if (*(char *)(param_1 + 7) == '\0') {
    cVar1 = func_0x80036c68(param_1,9,0xf,0);
    *(char *)(param_1 + 7) = *(char *)(param_1 + 7) + cVar1;
  }
  else if (*(char *)(param_1 + 7) == '\x01') {
    *(undefined4 *)(param_1 + 4) = 0x1010000;
  }
  return;
}
