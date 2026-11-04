/* FUN_80163b24
 * image   ovl_00a0344 (ovl), base 0x80161cf0
 * address 0x80163b24  body 0x80163b24..0x80163b4f  size 44 B
 * body sha256 4da1bd2790fb52ee1a97a37453863e240406e724279024b212f580e62a315845
 * provider record sha256 4a83acf55ab53f1ef4a4b69d25579486b02a2ab9b5e57e79bbe01454a3055914
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80163b24(int param_1,uint param_2)

{
  if ((param_2 & 0x40) == 0) {
    *(char *)(param_1 + 5) = (char)param_2;
    *(undefined2 *)(param_1 + 6) = 0;
    return;
  }
  *(uint *)(param_1 + 4) = (param_2 & 0xf) * 0x10000 + 0x2000000;
  return;
}
