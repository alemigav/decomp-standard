/* FUN_801627c8
 * image   ovl_008505e (ovl), base 0x80161cf0
 * address 0x801627c8  body 0x801627c8..0x801628bb  size 244 B
 * body sha256 8025e6a70a8936fd80c0d9964fd187d1d782767f7f934be861cd0b2319e8d28d
 * provider record sha256 deca7f46bce6ac9eee81c683ba6c08979b18fca9de1e84694919b234ae293ff9
 * callees 3 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_801627c8(uint *param_1)

{
  int iVar1;
  uint uVar2;
  undefined1 uVar3;
  
  *(undefined1 *)((int)param_1 + 6) = 1;
  param_1[0x7a] = 0x2000f00;
  *(undefined1 *)(param_1 + 0xb2) = 0;
  *(undefined1 *)((int)param_1 + 0x2b5) = 0;
  *(undefined1 *)((int)param_1 + 0x2c9) = 0;
  *(byte *)((int)param_1 + 0x26f) = *(byte *)((int)param_1 + 0x26f) & 0x7f;
  *(byte *)(param_1 + 0x97) = *(byte *)(param_1 + 0x97) & 0xfd;
  *param_1 = *param_1 & 0xefffffff | 0xc000000;
  *(undefined2 *)(param_1 + 0xb0) = 0x60;
  iVar1 = func_0x80036ed8(param_1,0,0x20,0);
  if (iVar1 != 0) {
    uVar2 = func_0x80033604();
    *(undefined2 *)(param_1 + 0xb0) = *(undefined2 *)(&DAT_80166da8 + (uVar2 & 7) * 2);
  }
  if (*(char *)((int)param_1 + 0x2ca) != '\0') {
    *(undefined2 *)((int)param_1 + 6) = 0x300;
    uVar3 = func_0x80065628();
    *(undefined1 *)(param_1 + 0xad) = uVar3;
    *(undefined1 *)(param_1 + 0xb2) = 1;
    *(undefined1 *)(param_1 + 0xb3) = 0;
    *(undefined2 *)((int)param_1 + 0x1f6) = 0;
  }
  return;
}
