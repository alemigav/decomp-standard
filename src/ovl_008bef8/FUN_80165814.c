/* FUN_80165814
 * image   ovl_008bef8 (ovl), base 0x80161cf0
 * address 0x80165814  body 0x80165814..0x80165a43  size 560 B
 * body sha256 a920cf07331e053f05bd435f9e8cf3f6b29bb4318d43bc271a1e23d90cd74604
 * provider record sha256 dafb29160099961182ee69d07c4f88a507b44ce72be058c4fa234d8b65fac00f
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80165814(int param_1)

{
  int iVar1;
  byte bVar2;
  int iVar3;
  short local_18;
  short local_16;
  short local_14;
  
  bVar2 = *(byte *)(param_1 + 0x2cd);
  iVar3 = *(int *)(param_1 + 0x234);
  if (bVar2 == 1) {
    iVar1 = func_0x80033604();
    local_18 = (short)((iVar1 << 0x18) >> 0x17) + 300;
    iVar1 = func_0x80033604();
    local_16 = (short)((iVar1 << 0x18) >> 0x17);
    iVar1 = func_0x80033604();
    local_14 = (short)((iVar1 << 0x18) >> 0x16) + 200;
    func_0x80037780(0x26032000,0,iVar3 + 0x908,&local_18);
LAB_801658d8:
    iVar1 = func_0x80033604();
    local_18 = (short)((iVar1 << 0x18) >> 0x16) + 300;
    iVar1 = func_0x80033604();
    local_16 = (short)((iVar1 << 0x18) >> 0x17);
    iVar1 = func_0x80033604();
    local_14 = (short)((iVar1 << 0x18) >> 0x17) + 200;
    iVar1 = func_0x80033604();
    func_0x80037780(0x64000,(iVar1 << 0x18) >> 0x14,iVar3 + 0xa80,&local_18);
    iVar1 = func_0x80033604();
    local_18 = (short)((iVar1 << 0x18) >> 0x16) + 300;
    iVar1 = func_0x80033604();
    local_16 = (short)((iVar1 << 0x18) >> 0x17);
    iVar1 = func_0x80033604();
    local_14 = (short)((iVar1 << 0x18) >> 0x17) + 200;
    iVar1 = func_0x80033604();
    func_0x80037780(0x34000,(iVar1 << 0x18) >> 0x14,iVar3 + 0xa80,&local_18);
    iVar1 = func_0x80033604();
    local_18 = (short)((iVar1 << 0x18) >> 0x17) + 300;
    iVar1 = func_0x80033604();
    local_16 = (short)((iVar1 << 0x18) >> 0x17);
    iVar1 = func_0x80033604();
    local_14 = (short)((iVar1 << 0x18) >> 0x16) + 200;
    iVar1 = func_0x80033604();
    func_0x80037780(0x8024000,(iVar1 << 0x18) >> 0x14,iVar3 + 0x908,&local_18);
    iVar1 = func_0x80033604();
    func_0x80037780(0x8024000,(iVar1 << 0x18) >> 0x14,iVar3 + 0x908,&local_18);
  }
  else {
    if (bVar2 < 2) {
      if (bVar2 == 0) {
        *(code **)(param_1 + 0x2d0) = FUN_80165814;
        *(char *)(param_1 + 0x2cd) = *(char *)(param_1 + 0x2cd) + '\x01';
        return;
      }
      goto LAB_80165a18;
    }
    if (bVar2 < 9) goto LAB_801658d8;
  }
  bVar2 = *(byte *)(param_1 + 0x2cd);
LAB_80165a18:
  if (bVar2 == 0x40) {
    *(undefined4 *)(param_1 + 0x2d0) = 0;
  }
  *(char *)(param_1 + 0x2cd) = *(char *)(param_1 + 0x2cd) + '\x01';
  return;
}
