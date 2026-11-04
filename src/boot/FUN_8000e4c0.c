/* FUN_8000e4c0
 * image   boot (boot), base 0x80000480
 * address 0x8000e4c0  body 0x8000e4c0..0x8000e657  size 408 B
 * body sha256 1dc1949b56955a0fc71204c85e317ddf87369f37265eb34521d762e4e0c6c465
 * provider record sha256 1fb38fcdc447b26aff6ffd389f51f4452cff9c6d16906a96d332cce4bae290f2
 * callees 10 direct (10 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8000e4c0(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  if (_DAT_800129e0 == 0) {
    FUN_8000df10();
    osCreateMesgQueue(0x80018a20,0x80018a38,5);
    _DAT_80018a50 = 0xd;
    DAT_80018a52 = 0;
    _DAT_80018a54 = 0;
    _DAT_80018a68 = 0xe;
    DAT_80018a6a = 0;
    _DAT_80018a6c = 0;
    osSetEventMesg(7,0x80018a20);
    osSetEventMesg(3,0x80018a20,&DAT_80018a68);
    iVar1 = FUN_80007010(0);
    iVar3 = -1;
    if (iVar1 < param_1) {
      FUN_8000cdf0(0,param_1);
      iVar3 = iVar1;
    }
    uVar2 = FUN_800072e0();
    _DAT_800129e0 = 1;
    _DAT_800129e4 = 0x80017868;
    _DAT_800129e8 = 0x80018a20;
    _DAT_800129ec = 0x80018a20;
    _DAT_800129f0 = 0;
    _DAT_800129f4 = 0;
    _DAT_800129f8 = 0;
    osCreateThread(0x80017868,0,FUN_8000e658,&DAT_800129e0,0x80018a20,param_1);
    FUN_8000e3b0();
    osStartThread(0x80017868);
    FUN_80007300(uVar2);
    if (iVar3 != -1) {
      FUN_8000cdf0(0,iVar3);
    }
  }
  return;
}
