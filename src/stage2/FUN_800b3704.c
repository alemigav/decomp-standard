/* FUN_800b3704
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800b3704  body 0x800b3704..0x800b398b  size 648 B
 * body sha256 4e3a748945256d3bbaf90f4b2195d717824f92ac5e2f4663da3912a603307ec6
 * provider record sha256 a047c43fbe74773bd4028f49b99acaeadb3e714a41151959d5383039095840c6
 * callees 7 direct (7 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
FUN_800b3704(uint param_1,int param_2,undefined1 param_3,undefined1 param_4,undefined1 param_5,
            undefined1 param_6,undefined1 param_7)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  
  if ((DAT_80136d80 != '\0') && (iVar5 = 0, param_1 < _DAT_8015af80)) {
    iVar3 = -0x7fea74e0;
    do {
      if (*(char *)(iVar3 + 0x1200) == '\0') break;
      iVar5 = iVar5 + 1;
      iVar3 = iVar3 + 0x1228;
    } while (iVar5 < 2);
    if (iVar5 != 2) {
      iVar3 = iVar5 * 0x1228;
      osCreateMesgQueue(iVar3 + -0x7fea6300,iVar3 + -0x7fea62e8,2);
      if ((param_2 == 0) && (param_2 = 16000, *(char *)(param_1 * 4 + _DAT_8015af7c) == '\0')) {
        param_2 = 8000;
      }
      *(undefined1 *)(iVar3 + -0x7fea62dc) = param_3;
      *(int *)(iVar3 + -0x7fea62d8) = param_2;
      *(undefined1 *)(iVar3 + -0x7fea62df) = param_4;
      *(undefined1 *)(iVar3 + -0x7fea62de) = param_5;
      *(undefined1 *)(iVar3 + -0x7fea62dd) = param_6;
      *(undefined1 *)(iVar3 + -0x7fea62c7) = param_7;
      uVar4 = _DAT_8015af90 & 1;
      *(uint *)(iVar3 + -0x7fea62cc) = (((uint)(param_2 << 3) / 0x1e + 0x9f) / 0xa0) * 0xa0;
      if (uVar4 == 0) {
        uVar2 = FUN_800a9420();
        uVar1 = (*_DAT_80144008)(uVar2,0);
        *(undefined4 *)(iVar3 + -0x7fea62d0) = uVar1;
        func_0x80007320(uVar1,uVar2);
      }
      else {
        *(undefined4 *)(iVar3 + -0x7fea62d0) = *(undefined4 *)(&DAT_8015af88 + iVar5 * 4);
      }
      if (*(int *)(iVar3 + -0x7fea62d0) != 0) {
        osRecvMesg(0x8015afa0,0,1);
        FUN_800b4930(iVar3 + -0x7fea74e0,
                     (*(uint *)(param_1 * 4 + _DAT_8015af7c) & 0xffffff) + _DAT_8015af78,
                     *(undefined4 *)(iVar3 + -0x7fea62d0),*(undefined4 *)(iVar3 + -0x7fea62cc),
                     FUN_800b44f4);
        if (DAT_80143fe8 != '\0') {
          (&DAT_80159cfe)[iVar3] = (&DAT_80159cfe)[iVar3] << 1;
        }
        *(undefined4 *)(iVar3 + -0x7fea62d4) = 0xffffffff;
        (&DAT_80159d20)[iVar3] = 1;
        osSendMesg(0x8015afa0,0,0);
        uVar2 = FUN_800b3640(iVar5);
        return uVar2;
      }
    }
  }
  return 0xffffffff;
}
