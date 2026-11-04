/* FUN_800988a4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800988a4  body 0x800988a4..0x80098a03  size 352 B
 * body sha256 c03388d2770ed95f8fc1f72964e4414e9abd05c6dc5f10bb13f8987e5b2fe008
 * provider record sha256 4b79aabdd794e0e789fe2d1228aaca983bacc8bd4c47e93c14170cb5039f1ef6
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800988a4(int param_1)

{
  int iVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  short sVar5;
  short sVar6;
  
  iVar1 = DAT_800c52dc;
  iVar3 = DAT_800c52dc + 0x3fb00;
  iVar4 = DAT_800c52dc + 0x3f800;
  sVar6 = DAT_8012bfe6 + DAT_8012fe56;
  sVar5 = DAT_8012bfe4 + DAT_8012fe54;
  if (DAT_800dfbe8 != '\0') {
    iVar3 = DAT_800c52dc + 0x3fb14;
  }
  if (param_1 == 0) {
    sVar2 = DAT_8012bfe4 + 0x32;
  }
  else {
    sVar2 = DAT_8012bfe4 + 0x10;
  }
  FUN_800478b8(iVar3,sVar2,DAT_8012bfe6 + 10);
  DAT_800df8b4 = FUN_80043988(DAT_800df8b4,iVar3,0,0);
  if (param_1 != 0) {
    if (DAT_800dfbe8 != '\0') {
      iVar4 = iVar1 + 0x3f814;
    }
    FUN_800478b8(iVar4,sVar5,sVar6);
    FUN_800479bc(iVar4,DAT_8012fe58,DAT_8012fe5a);
    if (DAT_8012bf9a == '\x02') {
      DAT_800df8b4 = FUN_80043988(DAT_800df8b4,iVar4,0x70,0x48);
    }
  }
  return;
}
