/* FUN_80165bd0
 * image   ovl_00a1414 (ovl), base 0x80161cf0
 * address 0x80165bd0  body 0x80165bd0..0x80165dcb  size 508 B
 * body sha256 1bc2c5d9d56e56c2b01e4aec0e060d3930b57c42a3d20c6c2e2ec275bca42b3b
 * provider record sha256 c51c059eea50eabc98b77a1ec3db2a722b222c5f540b6eba6a1b9f981fef071c
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80165bd0(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  switch(*(undefined1 *)(param_1 + 6)) {
  case 0:
    *(undefined4 *)(param_1 + 0x1e8) = 0x1001f00;
    *(undefined2 *)(param_1 + 500) = 0x3c;
    *(undefined1 *)(param_1 + 0x25c) = 0;
    if ((*(ushort *)(param_1 + 0x270) & 1) != 0) {
      *(undefined1 *)(param_1 + 6) = 1;
    }
    break;
  case 1:
    func_0x800334c8(param_1,param_2,param_3,0);
    func_0x80089d54(param_1,param_2,param_3,0x80);
    func_0x80032b5c(param_1,0);
    if ((*(ushort *)(param_1 + 0x270) & 2) != 0) {
      *(undefined1 *)(param_1 + 6) = 2;
    }
    break;
  case 2:
    *(undefined4 *)(param_1 + 0x1e8) = 0x1f00;
    *(undefined1 *)(param_1 + 6) = 3;
  case 3:
    uVar1 = *(undefined4 *)(param_1 + 0x22c);
    uVar2 = *(undefined4 *)(param_1 + 0x230);
    func_0x800334c8(param_1,uVar1,uVar2,0);
    func_0x80089d54(param_1,uVar1,uVar2,0x80);
    func_0x80032b5c(param_1,0);
    if ((*(ushort *)(param_1 + 0x270) & 4) != 0) {
      *(undefined1 *)(param_1 + 6) = 4;
    }
    break;
  case 4:
    *(undefined4 *)(param_1 + 0x1e8) = 0x1001f00;
    *(undefined2 *)(param_1 + 500) = 0x3c;
    *(undefined1 *)(param_1 + 6) = 5;
  case 5:
    func_0x800334c8(param_1,param_2,param_3,0);
    func_0x80089d54(param_1,param_2,param_3,0x80);
    func_0x80032b5c(param_1,0);
  }
  *(short *)(*(int *)(*(int *)(param_1 + 0x234) + 0x298) + 0xc) =
       (char)(&DAT_80168fe8)[*(char *)(param_1 + 0x2ba)] * -5 + 0x1000;
  func_0x80066288(param_1);
  *(short *)(*(int *)(*(int *)(param_1 + 0x234) + 0x410) + 0xc) =
       (char)(&DAT_80168fe8)[*(char *)(param_1 + 0x2ba)] * -5 + 0x1000;
  func_0x80066288();
  return;
}
