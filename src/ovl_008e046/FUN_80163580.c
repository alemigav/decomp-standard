/* FUN_80163580
 * image   ovl_008e046 (ovl), base 0x80161cf0
 * address 0x80163580  body 0x80163580..0x801637c7  size 584 B
 * body sha256 87afecb204885bfa9bcd28bf0d1407d290dc281095140b8d474e439eb0382ad0
 * provider record sha256 d6220f2cf3a24b326090de946733ae284949785a6a82b3e8343eb0e495db7715
 * callees 5 direct (5 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80163580(int param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  short unaff_s1;
  
  bVar1 = *(byte *)(param_1 + 6);
  if (bVar1 != 1) {
    if (1 < bVar1) {
      if (bVar1 != 2) {
        return;
      }
      goto LAB_801636a0;
    }
    if (bVar1 != 0) {
      return;
    }
    if (*(int *)(param_1 + 0x2c4) != 0) {
      *(undefined4 *)(param_1 + 0x1e8) = 0x2000f00;
      *(undefined1 *)(param_1 + 0x2ce) = 3;
      *(undefined1 *)(param_1 + 6) = 2;
      *(ushort *)(param_1 + 0x2c8) = *(ushort *)(param_1 + 0x2c8) & 0xfffd;
      goto LAB_801636a0;
    }
    *(undefined4 *)(param_1 + 0x1e8) = 0x4000f00;
    *(undefined1 *)(param_1 + 0x2ce) = 3;
    *(undefined1 *)(param_1 + 6) = 1;
    *(ushort *)(param_1 + 0x2c8) = *(ushort *)(param_1 + 0x2c8) & 0xfffd;
  }
  uVar2 = FUN_80162768(param_1);
  *(undefined4 *)(param_1 + 0x2c4) = uVar2;
  *(char *)(param_1 + 7) = *(char *)(param_1 + 7) + '\x01';
  func_0x8008a994(param_1,param_2,param_3,0x100);
  if (*(int *)(param_1 + 0x2c4) == 0) {
    if (*(byte *)(param_1 + 7) < 0x79) {
      return;
    }
    *(undefined4 *)(param_1 + 4) = 0x1040000;
    *(undefined4 *)(param_1 + 0x1e8) = 0x2000f00;
    return;
  }
  *(undefined4 *)(param_1 + 0x1e8) = 0x2000f00;
  *(undefined1 *)(param_1 + 6) = 2;
LAB_801636a0:
  iVar3 = func_0x80032e74(param_1,*(undefined4 *)(*(int *)(param_1 + 0x2c4) + 0x28),
                          *(undefined4 *)(*(int *)(param_1 + 0x2c4) + 0x30),0x200);
  if (iVar3 == 0) {
    iVar3 = *(int *)(*(int *)(param_1 + 0x2c4) + 0x28) - *(int *)(param_1 + 0x28);
    iVar4 = *(int *)(*(int *)(param_1 + 0x2c4) + 0x30) - *(int *)(param_1 + 0x30);
    iVar3 = func_0x80040bb4(iVar3 * iVar3 + iVar4 * iVar4);
    if (iVar3 < 4000) {
      unaff_s1 = func_0x80032e74(param_1,*(undefined4 *)(*(int *)(param_1 + 0x2c4) + 0x28),
                                 *(undefined4 *)(*(int *)(param_1 + 0x2c4) + 0x30),0x40);
    }
    else {
      unaff_s1 = func_0x80032e74(param_1,*(undefined4 *)(*(int *)(param_1 + 0x2c4) + 0x28),
                                 *(undefined4 *)(*(int *)(param_1 + 0x2c4) + 0x30),0x10);
      *(char *)(param_1 + 7) = *(char *)(param_1 + 7) + '\x01';
    }
    *(undefined2 *)(param_1 + 0x1e0) = 0xffd8;
    *(undefined2 *)(param_1 + 0x1e4) = 0;
    *(short *)(param_1 + 0x66) = *(short *)(param_1 + 0x66) + unaff_s1;
    func_0x80032b5c(param_1,0);
  }
  else {
    *(undefined4 *)(param_1 + 4) = 0x1130000;
  }
  func_0x8008a994(param_1,param_2,param_3,0x100);
  if (unaff_s1 == 0) {
    *(undefined4 *)(param_1 + 4) = 0x1020000;
  }
  if (0x20 < *(byte *)(param_1 + 7)) {
    *(undefined4 *)(param_1 + 4) = 0x1050000;
  }
  return;
}
