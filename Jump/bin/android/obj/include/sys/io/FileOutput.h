#ifndef INCLUDED_sys_io_FileOutput
#define INCLUDED_sys_io_FileOutput

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <haxe/io/Output.h>
HX_DECLARE_CLASS2(haxe,io,Bytes)
HX_DECLARE_CLASS2(haxe,io,Output)
HX_DECLARE_CLASS2(sys,io,FileOutput)
HX_DECLARE_CLASS2(sys,io,FileSeek)
namespace sys{
namespace io{


class FileOutput_obj : public ::haxe::io::Output_obj{
	public:
		typedef ::haxe::io::Output_obj super;
		typedef FileOutput_obj OBJ_;
		FileOutput_obj();
		Void __construct(Dynamic f);

	public:
		static hx::ObjectPtr< FileOutput_obj > __new(Dynamic f);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~FileOutput_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("FileOutput"); }

		virtual int tell( );
		Dynamic tell_dyn();

		virtual Void seek( int p,::sys::io::FileSeek pos);
		Dynamic seek_dyn();

		virtual Void close( );

		virtual Void flush( );

		virtual int writeBytes( ::haxe::io::Bytes s,int p,int l);

		virtual Void writeByte( int c);

		Dynamic __f; /* REM */ 
		static Dynamic file_close; /* REM */ 
		static Dynamic &file_close_dyn() { return file_close;}
		static Dynamic file_seek; /* REM */ 
		static Dynamic &file_seek_dyn() { return file_seek;}
		static Dynamic file_tell; /* REM */ 
		static Dynamic &file_tell_dyn() { return file_tell;}
		static Dynamic file_flush; /* REM */ 
		static Dynamic &file_flush_dyn() { return file_flush;}
		static Dynamic file_write; /* REM */ 
		static Dynamic &file_write_dyn() { return file_write;}
		static Dynamic file_write_char; /* REM */ 
		static Dynamic &file_write_char_dyn() { return file_write_char;}
};

} // end namespace sys
} // end namespace io

#endif /* INCLUDED_sys_io_FileOutput */ 
