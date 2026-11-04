/* FUN_80162a78
 * image   ovl_00a43b6 (ovl), base 0x80161cf0
 * address 0x80162a78  body 0x80162a78..0x80162b4f  size 216 B
 * body sha256 59a89fcaa9e1a86e5f714132b068aaa1068eb129946f92c3e2e265db0a82f1b4
 * provider record sha256 3680eaa6029f5d68b911ad5541daf90cef1a13843c4ccbc388c1f34ad2f10827
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80162a78(int param_1)

{
  short sVar1;
  short sVar2;
  uint uVar3;
  
  uVar3 = *(uint *)(param_1 + 0x28c);
  func_0x80032e74(param_1,_DAT_800e1158,_DAT_800e1160,0x5f4);
  sVar1 = func_0x80032e74(param_1,_DAT_800e1158,_DAT_800e1160,0x270);
  sVar2 = func_0x80032e74(param_1,_DAT_800e1158,_DAT_800e1160,0x400);
  if ((sVar2 == 0) && (uVar3 < 0x5dc)) {
    *(undefined4 *)(param_1 + 4) = 0x1050000;
  }
  if ((((*(char *)(param_1 + 0x2b6) == '\0') && (DAT_800e139f == '\0')) && (sVar1 == 0)) &&
     (uVar3 < 3000)) {
    *(undefined4 *)(param_1 + 4) = 0x1020000;
  }
  return;
}
