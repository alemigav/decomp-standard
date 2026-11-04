/* FUN_801648a8
 * image   ovl_008505e (ovl), base 0x80161cf0
 * address 0x801648a8  body 0x801648a8..0x801648ef  size 72 B
 * body sha256 14c5e573f0922eec7f76585740f23eff33ad7d1faefdbdf36fb1c6f6255ae6c8
 * provider record sha256 ffd8e9c2a9200ba6a22f8cc4a094f7233492a858331f4eb6b7ff171f62f97209
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_801648a8(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_8016313c();
  if (iVar1 != 0) {
    *(undefined1 *)(param_1 + 5) = 2;
    *(undefined2 *)(param_1 + 6) = 0;
    *(undefined1 *)(param_1 + 0x2b9) = 0;
    *(undefined1 *)(param_1 + 0x2c8) = 0;
    *(byte *)(param_1 + 0x26f) = *(byte *)(param_1 + 0x26f) & 0x7f;
  }
  return;
}
