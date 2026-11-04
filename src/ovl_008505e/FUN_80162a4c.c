/* FUN_80162a4c
 * image   ovl_008505e (ovl), base 0x80161cf0
 * address 0x80162a4c  body 0x80162a4c..0x80162b67  size 284 B
 * body sha256 c86e9b88b0d74ef774ea96bc43811d005f519f255c796df372b82b6b1c803a71
 * provider record sha256 72f89629e2527cb82a176222581bd29b4a5438eebc3b708efdd7d1fa0c8b71a2
 * callees 7 direct (7 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80162a4c(int param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  if (*(char *)(param_1 + 7) == '\0') {
    *(undefined1 *)(param_1 + 7) = 1;
    *(undefined2 *)(param_1 + 500) = 0;
  }
  iVar1 = FUN_80166bd4(param_1);
  func_0x800653d0(param_1,iVar1 + 0x28,0,0);
  uVar2 = func_0x80032e74(param_1,(int)*(short *)(param_1 + 0x260),(int)*(short *)(param_1 + 0x262),
                          0x60);
  func_0x80032b5c(param_1,-(int)*(short *)(param_1 + 500));
  FUN_80166590(param_1,(int)(short)uVar2);
  if (*(char *)(param_1 + 7) == '\x01') {
    FUN_8016655c(param_1,6,10);
    if (*(short *)(param_1 + 0x1e0) < 0xb) {
      *(char *)(param_1 + 7) = *(char *)(param_1 + 7) + '\x01';
    }
  }
  else {
    FUN_80166528(param_1,6,0xf0);
  }
  iVar3 = *(ushort *)(param_1 + 500) + uVar2;
  iVar1 = iVar3 * 0x10000 >> 0x10;
  *(short *)(param_1 + 0x66) = *(short *)(param_1 + 0x66) + (short)uVar2;
  *(short *)(param_1 + 500) = (short)iVar3;
  if (iVar1 < 0) {
    iVar1 = -iVar1;
  }
  if ((0x7ff < iVar1) || ((uVar2 & 0xffff) == 0)) {
    *(undefined1 *)(param_1 + 6) = 1;
  }
  return;
}
