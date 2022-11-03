#include <ntdef.h>
#include <ntifs.h>
#include <ntimage.h>
#include <windef.h>

#include "definitions.h"
#include "utils.h"
#include "Hook.h"

auto DriverEntry( ) -> NTSTATUS
{
	const auto win32k = utils::get_kernel_module( "win32k.sys" );

	uintptr_t address = win32k.base + 0x654F0; // data ptr offset 

	if ( !address )
	{
		dbg( "address not found" );

	}
	else
	{
		dbg( "found address at : %llX", address );

	}


	/*const auto hookaddress = *(uintptr_t *)( address );
	*(uintptr_t *)( address ) = (uintptr_t)( hello );*/

	uintptr_t testhook = *reinterpret_cast<uintptr_t *>( address );
	*reinterpret_cast<uintptr_t *>( address ) = reinterpret_cast<uintptr_t>( &hello );

	dbg( "found testhook at : %llp", testhook );
	
	return STATUS_SUCCESS;
}
