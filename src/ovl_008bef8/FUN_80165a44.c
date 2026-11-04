/* FUN_80165a44
 * image   ovl_008bef8 (ovl), base 0x80161cf0
 * address 0x80165a44  body 0x80165a44..0x80165b97  size 340 B
 * body sha256 f731c84f509a7c320ec956d20b2318c16258062095dde0e6c5837fd980eedebf
 * provider record sha256 0a9086407f2e33019cfbe53fe4d0485b8c394bc6f30e680ec2c05bd526fcda32
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80165a44(int param_1,int param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  short local_20 [4];
  
  iVar4 = *(int *)(param_1 + 0x234);
  iVar1 = func_0x80033604();
  local_20[0] = (short)((iVar1 << 0x18) >> 0x17);
  local_20[1] = 0xfe70;
  local_20[2] = 0;
  iVar1 = func_0x80033604();
  uVar3 = param_2 << 0x18 | param_3 << 0x10;
  uVar2 = uVar3 | 0x2000;
  iVar4 = iVar4 + 0xa80;
  func_0x80037780(uVar2,(iVar1 << 0x18) >> 0x14,iVar4,local_20);
  iVar1 = func_0x80033604();
  local_20[0] = (short)((iVar1 << 0x18) >> 0x17) + 300;
  local_20[1] = 0xfed4;
  local_20[2] = 900;
  iVar1 = func_0x80033604();
  func_0x80037780(uVar2,(iVar1 << 0x18) >> 0x14,iVar4,local_20);
  iVar1 = func_0x80033604();
  local_20[0] = (short)((iVar1 << 0x18) >> 0x17) + -600;
  local_20[1] = 0xff38;
  local_20[2] = 0xfc18;
  iVar1 = func_0x80033604();
  func_0x80037780(uVar2,(iVar1 << 0x18) >> 0x14,iVar4,local_20);
  iVar1 = func_0x80033604();
  local_20[0] = (short)((iVar1 << 0x18) >> 0x17) + -400;
  local_20[1] = 0xfe70;
  local_20[2] = 200;
  iVar1 = func_0x80033604();
  func_0x80037780(uVar3 | 0x2800,(iVar1 << 0x18) >> 0x14,iVar4,local_20);
  return;
}
