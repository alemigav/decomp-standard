/* FUN_801655f4
 * image   ovl_008bef8 (ovl), base 0x80161cf0
 * address 0x801655f4  body 0x801655f4..0x801656e3  size 240 B
 * body sha256 3b3cd6f2988da379d556204b6589d3b07a94b90fe4cb8af77aa6ec2dd39f4982
 * provider record sha256 3b48e75e76466250b55868623b44804a0c86862d27e8851b87612539c7efe2d4
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_801655f4(int param_1)

{
  uint uVar1;
  ushort uVar2;
  int iVar3;
  short local_18;
  short local_16;
  short local_14;
  
  if (*(char *)(param_1 + 0x2cf) == '\0') {
    uVar1 = func_0x80033604();
    DAT_80166364 = uVar1 & 7;
  }
  *(undefined1 *)(param_1 + 0x2cf) = 4;
  iVar3 = DAT_80166364 * 0xc;
  uVar2 = func_0x80033604();
  local_18 = *(short *)(&DAT_80166134 + iVar3) + -0x7f + (uVar2 & 0xff) * 2;
  uVar2 = func_0x80033604();
  local_16 = *(short *)(&DAT_80166136 + iVar3) + -0x7f + (uVar2 & 0xff) * 2;
  uVar2 = func_0x80033604();
  local_14 = *(short *)(&DAT_80166138 + iVar3) + -0x7f + (uVar2 & 0xff) * 2;
  FUN_80165e14(param_1,0,6,0x2800,(int)*(short *)(&DAT_8016613a + iVar3),
               *(undefined4 *)(&DAT_8016613c + iVar3),&local_18);
  return;
}
