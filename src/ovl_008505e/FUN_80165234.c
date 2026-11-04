/* FUN_80165234
 * image   ovl_008505e (ovl), base 0x80161cf0
 * address 0x80165234  body 0x80165234..0x801652ff  size 204 B
 * body sha256 a900374d106a703cecb537e55d54bcae37af246a86ea40bbd1aa81c42be7efe2
 * provider record sha256 819dff20324ef6a39a92464db48d3593b29eb005fa182b24ba374c0cb2e9ad78
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80165234(uint *param_1)

{
  ushort uVar2;
  uint uVar1;
  undefined *puVar3;
  
  if (*(char *)((int)param_1 + 7) == '\0') {
    *(undefined1 *)((int)param_1 + 7) = 1;
    uVar2 = func_0x80033604();
    if ((_DAT_800e10ec & 0x20) == 0) {
      uVar1 = func_0x80033604();
      puVar3 = &DAT_80166c98;
    }
    else {
      uVar1 = func_0x80033604();
      puVar3 = &DAT_80166cb8;
    }
    *(ushort *)((int)param_1 + 0x1f2) = *(short *)(puVar3 + (uVar1 & 0xf) * 2) + (uVar2 & 3);
    *(undefined1 *)((int)param_1 + 0x1ef) = 0xd;
    *(undefined1 *)((int)param_1 + 0x1ee) = 0xd;
    *(undefined1 *)((int)param_1 + 0x1ed) = 0xd;
    *param_1 = *param_1 & 0xe3ffffff;
    *(byte *)((int)param_1 + 0x26f) = *(byte *)((int)param_1 + 0x26f) | 0x80;
  }
  return;
}
