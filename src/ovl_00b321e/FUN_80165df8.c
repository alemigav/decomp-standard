/* FUN_80165df8
 * image   ovl_00b321e (ovl), base 0x80161cf0
 * address 0x80165df8  body 0x80165df8..0x80165e9f  size 168 B
 * body sha256 ed020c3720676986ba88b26a292b5f811447d9f512d3cf31c1f4913a175bde5e
 * provider record sha256 6177e9c7ad1522359b4eb1f90361127498511ecc0f0ab69db905ab9a8e9ae8aa
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80165df8(undefined4 param_1,int param_2)

{
  if (*(char *)(param_2 + 7) == '\0') {
    *(undefined1 *)(param_2 + 1) = 0;
  }
  FUN_80165ea0(param_1,param_2);
  if (*(char *)(param_2 + 1) == '\0') {
    if (*(char *)(param_2 + 7) == '\x02') {
      *(undefined1 *)(param_2 + 1) = 1;
    }
  }
  else if (*(char *)(param_2 + 7) == '\x01') {
    *(byte *)(param_2 + 9) = *(byte *)(param_2 + 9) & 0x7f;
  }
  FUN_80165bd0(param_1,0x83,(int)*(short *)(param_2 + 2),0);
  FUN_80165bd0(param_1,0x84,(int)*(short *)(param_2 + 4),0);
  return;
}
