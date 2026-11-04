/* FUN_801658a8
 * image   ovl_008e046 (ovl), base 0x80161cf0
 * address 0x801658a8  body 0x801658a8..0x80165973  size 204 B
 * body sha256 9114959639fe5cb44dc9d4893339fe93af6579985bc3f882b94e416b9e66e98e
 * provider record sha256 0a5d01cfdce6f57adc64076351d65943dc7aeb9990943f5e4cac2c4c492d3b37
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_801658a8(uint *param_1,undefined4 param_2,undefined4 param_3)

{
  bool bVar1;
  
  if (*(char *)((int)param_1 + 5) != -1) {
    *(undefined1 *)((int)param_1 + 0x2cb) = *(undefined1 *)((int)param_1 + 5);
    bVar1 = DAT_80167540 == *(byte *)(param_1 + 3);
    param_1[0xb1] = 0x800e1130;
    if (bVar1) {
      DAT_80167540 = 0;
    }
    *(undefined1 *)((int)param_1 + 5) = 0xff;
    *(undefined1 *)((int)param_1 + 0x2b5) = 2;
    FUN_80165974(param_1);
    if (*(char *)((int)param_1 + 0x26e) != '\0') {
      *param_1 = *param_1 & 0xfffffff1;
      *(ushort *)(param_1 + 0xb2) = *(ushort *)(param_1 + 0xb2) & 0xfd0f;
    }
  }
  (*(code *)(&PTR_FUN_801674f8)[*(byte *)((int)param_1 + 0x26e)])(param_1,param_2,param_3);
  return;
}
